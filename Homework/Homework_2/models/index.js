const Sequelize = require("sequelize");
const config = require("../config/config.json")["development"];
const User = require("./user");
const Post = require("./post");

sequelize = new Sequelize(
  config.database,
  config.username,
  config.password,
  config
);

const db = {};

User.init(sequelize);
Post.init(sequelize);

db.sequelize = sequelize;
db.User = User;
db.Post = Post;

module.exports = db;
