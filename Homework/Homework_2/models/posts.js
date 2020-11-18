const Sequelize = require("sequelize");

module.exports = class Posts extends Sequelize.Model {
  static init(sequelize) {
    return super.init(
      {
        text: {
          type: Sequelize.STRING(1000),
          allowNull: true,
        },
      },
      {
        sequelize,
        tableName: "users",
        modelName: "user",
        charset: "utf8",
        coLLate: "utf8_general_ci",
      }
    );
  }
};
