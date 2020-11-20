const router = require("express").Router();
const { Post, User } = require("../models");

// const jwt = require("jsonwebtoken");
// const middleware = require("../middleware/token");

router.post("/create", async (req, res) => {
  const text = req.body;
  console.log(text);
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

router.post("/delete", async (req, res) => {
  const { deleteID } = req.body;
  try {
    await Post.destroy({
      where: { id: deleteID },
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

router.post("/update", async (req, res) => {
  const { updateText, updateID } = req.body;
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

router.get("/read", async (req, res) => {
  const { readID } = req.body;
  console.log(readID);
  try {
    const postReadText = await Post.findAll({
      where: { id: readID.id },
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
