export default {
    entry: {
        script: "./public/js/script.js",
        userCardScript: "./public/js/userScript.js"
    },
    output: {
        filename: "[name].js",
        path: "./public/webpack"
    },
    module: {
        rules: [
            {
                test: /\.css$/,
                exclude: /node_modules/,
                use:  ["style-loader", "css-loader"],
            },
            {
                test: /\.less$/,
                exclude: /node_modules/,
                use: ["style-loader","css-loader","less-loader"],
            },
            {
                test: /\.(?:js|mjs|cjs)$/,
                exclude: /node_modules/,
                use: {
                    loader: "babel-loader",
                    options: {
                        presets: [
                            ['@babel/preset-env', { targets: "defaults" }]
                        ]
                    }
                }
            }
        ],
    },
}