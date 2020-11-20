const router = require("express").Router();
const { Post, User } = require("../models");

// const jwt = require("jsonwebtoken");
// const middleware = require("../middleware/token");

router.post("/create", async (req, res) => {
  const text = req.body;
  try {
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
  try {
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
  try {
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
  try {
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
