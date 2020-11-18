const router = require("express").Router();
const jwt = require("jsonwebtoken");
const { User } = require("../models");
const middleware = require("../middleware/token");

router.post("/signup", async (req, res) => {
  const { userId, password } = req.body;
  try {
    await User.create({
      userId,
      password,
    });
    res.status(200).json({
      message: "성공",
    });
  } catch (err) {
    console.log(err.message);
    res.status(409).json({
      message: "아이디 중복",
    });
  }
});

router.post("/login", middleware, async (req, res) => {
  const { userId, password } = req.body;
  const secret = req.app.get("jwt-secret");
  try {
    const user = await User.findOne({
      where: { userId },
    });
    if (user.password !== password) {
      throw new Error();
    }
    const token = jwt.sign(
      {
        userId,
      },
      secret,
      {
        expiresIn: "1h",
      }
    );
    res.status(200).json({
      message: "성공",
      accessToken: token,
    });
  } catch (err) {
    console.log(err.message);
    res.status(404).json({
      message: "틀린 비밀번호",
    });
  }
});

module.exports = router;
