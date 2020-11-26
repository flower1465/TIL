const express = require("express");
const morgan = require("morgan");
const dotenv = require("dotenv");
const { sequelize } = require("./models");
const routes = require("./routes");

dotenv.config();

const app = express();

app.use(morgan("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

const PORT = process.env.PORT || 3000;

sequelize
  .sync({ force: true })
  .then(() => {
    console.log("데이터베이스 연결 성공");
  })
  .catch((err) => {
    console.error(err);
  });

app.set("jwt-secret", process.env.JWT_SECRET);
app.use("/", routes);

app.listen(PORT, () => {
  console.log(PORT, "번 포트에서 대기 중");
});
