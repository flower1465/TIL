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
    res.status(409).json({
      message: "실패하셧습니다.",
    });
  }
});

router.delete("/delete/:id", async (req, res) => {
  const id = req.params.id;
  try {
    await Post.destroy({
      where: { id },
    });
    res.status(200).json({
      message: "성공",
    });
  } catch (err) {
    console.log(err.message);
    res.status(409).json({
      message: "실패하셧습니다.",
    });
  }
});

router.patch("/update/:id", async (req, res) => {
  const updateID = req.params.id;
  const updateText = req.body;
  try {
    await Post.update(
      {
        title: updateText.title,
        writer: updateText.writer,
      },
      {
        where: { id: updateID },
      }
    );
    res.status(200).json({
      message: "성공",
    });
  } catch (err) {
    console.log(err.message);
    res.status(409).json({
      message: "실패하셧습니다.",
    });
  }
});

router.get("/read/:id", async (req, res) => {
  const id = req.params.id;
  try {
    const postReadText = await Post.findOne({
      where: { id },
      attributes: ["title", "writer"],
    });
    res.status(200).json({
      message: postReadText,
    });
  } catch (err) {
    console.log(err.message);
    res.status(409).json({
      message: "실패하셧습니다.",
    });
  }
});

module.exports = router;
