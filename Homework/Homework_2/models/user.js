const Sequelize = require("sequelize");

module.exports = class User extends (
  Sequelize.Model
) {
  static init(sequelize) {
    return super.init(
      {
        userId: {
          type: Sequelize.STRING(30),
          allowNull: false,
        },
        password: {
          type: Sequelize.INTEGER,
          allowNull: false,
        },
        refreshToken: {
          type: Sequelize.STRING(300),
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
