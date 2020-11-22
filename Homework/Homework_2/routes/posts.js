const router = require("express").Router();
const middleware = require("../middleware/token");
const { Post, User } = require("../models");

router.post("/create", middleware, async (req, res) => {
  const text = req.body;
  const token = req.decoded;
  try {
    if (!token) {
      throw new Error();
    }
    await Post.create({
      title: text.title,
      writer: text.writer,
    });
    res.status(200).json({
      message: "성공",
    });
  } catch (err) {
    console.log(err.message);
    res.status(400).json({
      message: "실패하셧습니다.",
    });
  }
});

router.delete("/delete/:id", async (req, res) => {
  const id = req.params.id;
  const token = req.decoded;
  try {
    if (!token) {
      throw new Error();
    }
    const post = await Post.findOne({ where: { id } });
    if (!post) {
      throw new Error();
    }
    await post.destroy();
    res.status(200).json({
      message: "성공",
    });
  } catch (err) {
    console.log(err.message);
    res.status(404).json({
      message: "데이터베이스를 찾을 수 없습니다.",
    });
  }
});

router.patch("/update/:id", async (req, res) => {
  const id = req.params.id;
  const updateText = req.body;
  const token = req.decoded;
  try {
    if (!token) {
      throw new Error();
    }
    const post = await Post.findOne({ where: { id } });
    if (!post) {
      throw new Error();
    }
    await Post.update(
      {
        title: updateText.title,
        writer: updateText.writer,
      },
      {
        where: { id },
      }
    );
    res.status(200).json({
      message: "성공",
    });
  } catch (err) {
    console.log(err.message);
    res.status(404).json({
      message: "데이터베이스를 찾을 수 없습니다.",
    });
  }
});

router.get("/read/:id", async (req, res) => {
  const id = req.params.id;
  const token = req.decoded;
  try {
    if (!token) {
      throw new Error();
    }
    const post = await Post.findOne({ where: { id } });
    if (!post) {
      throw new Error();
    }
    const postReadText = await Post.findOne({
      where: { id },
      attributes: ["title", "writer"],
    });
    res.status(200).json({
      message: postReadText,
    });
  } catch (err) {
    console.log(err.message);
    res.status(404).json({
      message: "데이터베이스를 찾을 수 없습니다..",
    });
  }
});

module.exports = router;
