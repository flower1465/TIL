const router = require("express").Router();
const jwt = require("jsonwebtoken");
const { User } = require("../models");
const middleware = require("../middleware/token");

router.post("/signup", async (req, res) => {
  const { userId, password } = req.body;
  try {
    const ID = await User.findOne({
      where: {
        userId,
      },
    });
    if (ID) {
      res.status(410).json({
        message: "ID 중복",
      });
    }
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

router.post("/login", async (req, res) => {
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
    const refreshToken = jwt.sign(
      {
        userId,
      },
      secret,
      {
        expiresIn: "168h",
      }
    );
    res.status(200).json({
      message: "성공",
      accessToken: token,
      refresToken: refreshToken,
    });
  } catch (err) {
    console.log(err.message);
    res.status(404).json({
      message: "틀린 비밀번호",
    });
  }
});

router.post("/refresh", async (req, res) => {
  const refreshToken = req.headers["refresh-token"];
  const { userId } = req.body;
  const secret = req.app.get("jwt-secret");
  try {
    const user = await User.findOne({
      where: { refreshToken },
    });
    const token = jwt.sign(
      {
        userId,
      },
      secret,
      {
        expiresIn: "1h",
      }
    );
    res.status(200).json({ token, refreshToken });
  } catch (err) {
    console.log(err.message);
    res.status(404).json({
      message: "찾지 못하였습니다.",
    });
  }
});

module.exports = router;
