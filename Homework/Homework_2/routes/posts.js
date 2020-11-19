const router = require("express").Router();
const { Post } = require("../models");

// const jwt = require("jsonwebtoken");
// const middleware = require("../middleware/token");

router.post("/create", async (req, res) => {
  const { text } = req.body;
  try {
    await Post.create({
      text,
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
  const { text } = req.body;
  try {
    await Post.delete({
      text,
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
  const { text } = req.body;
  try {
    await Post.update({
      text,
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

router.post("/read", async (req, res) => {
  const { text } = req.body;
  try {
    await Post.select({
      text,
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

module.exports = router;
