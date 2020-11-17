const Sequelize = require("sequelize");

module.exports = class User extends Sequelize.Model {
  static init(sequelize) {
    return super.init({
      userId: {
        type: Sequelize.STRING(10),
        allowNull: false,
      },
      password: {
        type: Sequelize.INTEGER,
        allowNull: false,
      },
      refreshToken: {
        type: Sequelize.STRING(300),
        allowNull: false,
      },
    });
  }
};
