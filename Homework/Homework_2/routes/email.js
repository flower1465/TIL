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

router.post("/editmail", async (req, res, next) => {
  const email = req.body.email;
  try {
    const user = await User.findOne({
      where: { email },
    });
    if (user) {
      const token = crypto.randomBytes(20).toString("hex");
      const data = {
        token,
        userid: user.id,
        ttl: 300,
      };

      EmailUser.create(data);

      const transporter = nodemailer.createTransport({
        service: "gmail",
        port: 465,
        secure: true,
        auth: {
          user: process.env.user,
          pass: process.env.password,
        },
      });

      const mailOptions = {
        from: process.env.user,
        to: email,
        subject: "비밀번호 변경",
        html:
          `<p>비밀번호 초기화를 위해서 아래의 URL을 클릭하여 주세요.<p>` +
          `<a href='http://localhost:3000/resetpasswrod/${token}'>비밀번호 변경하기</a>`,
      };

      transporter.sendMail(mailOptions, (error, info) => {
        if (error) {
          console.log(error);
        } else {
          console.log("Email sent: " + info.response);
        }
      });
      return res.json(result);
    } else {
      return res.status(403).send("This account does not exist");
    }
  } catch (err) {
    res.send(err);
  }
});

module.exports = router;
