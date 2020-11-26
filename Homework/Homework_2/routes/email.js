const nodemailer = require("nodemailer");
const router = require("express").Router();
const dotenv = require("dotenv").config();

router.post("/email", (req, res) => {
  try {
    const email = req.body.email;

    const transporter = nodemailer.createTransport({
      service: "gmail",
      auth: {
        user: process.env.user,
        pass: process.env.password,
      },
    });

    const mailOptions = {
      from: process.env.use,
      to: email,
      subject: "이메일 전송",
      text: "성공 ㅎㅎ",
    };

    transporter.sendMail(mailOptions, (error, info) => {
      if (error) {
        console.log(error);
      } else {
        console.log("Email sent: " + info.response);
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
