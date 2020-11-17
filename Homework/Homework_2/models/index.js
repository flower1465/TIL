const Sequelize = require("sequelize");
const config = require("../config/config.json")["development"];

sequelize = new Sequelize(
  config.database,
  config.username,
  config.password,
  config
);

const db = {};

db.sequelize = sequelize;

module.exports = db;
