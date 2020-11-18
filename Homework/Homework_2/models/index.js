const Sequelize = require("sequelize");
const config = require("../config/config.json")["development"];
const User = require("./user");

sequelize = new Sequelize(
  config.database,
  config.username,
  config.password,
  config
);

const db = {};

User.init(sequelize);

db.sequelize = sequelize;
db.User = User;

module.exports = db;
