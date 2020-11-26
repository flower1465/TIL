const nodemailer = require("nodemailer");
const router = require("express").Router();
const dotenv = require("dotenv").config();

router.post("/mail", (req, res) => {
  try {
    const email = req.body.email;

    const transporter = nodemailer.createTransport({
      service: "gmail",
      auth: {
        user: "poodle2405@gmail.com",
        pass: process.env.password,
      },
    });

    const mailOptions = {
      from: "poodle2405@gmail.com",
      to: email,
      subject: "HTML 보내기",
      html: "<h1>HTML 보내기 성공</h1>",
    };

    transporter.sendMail(mailOptions, (err, info) => {
      if (err) {
        console.error("메일 보내기 에러 : ", err);
      } else {
        console.log("성공 : ", info);
      }
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

module.exports = router;
