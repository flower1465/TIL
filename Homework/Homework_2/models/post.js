const Sequelize = require("sequelize");

module.exports = class Post extends Sequelize.Model {
  static init(sequelize) {
    return super.init(
      {
        title: {
          type: Sequelize.STRING(255),
          allowNull: true,
        },
        writer: {
          type: Sequelize.STRING(1000),
          allowNull: true,
        },
      },
      {
        sequelize,
        tableName: "post",
        modelName: "post",
        charset: "utf8",
        coLLate: "utf8_general_ci",
      }
    );
  }
};
