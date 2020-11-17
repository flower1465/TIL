const jwt = require("jsonwebtoken");

const tokenMiddleware = async (req, res, next) => {
  const token = req.headers["access-token"];
  if (!token) {
    res.status(403).json({ message: "로그인 되어있지 않음" });
  }
  try {
    await jwt.verify(token, req.app.get("jwt-secret"), (err, decoded) => {
      if (err) throw new Error(err.message);
      req.decoded = decoded;
      next();
    });
  } catch (e) {
    res.status(403).json({
      message: "로그인 되어있지 않음",
    });
  }
};



module.exports = tokenMiddleware;
