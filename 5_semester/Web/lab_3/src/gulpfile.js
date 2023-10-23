import gulp from "gulp"
import less from "gulp-less"
import clean_css from "gulp-clean-css"
import babel from "gulp-babel"
import uglify from "gulp-uglify"


// Настройка путей
const paths = { 
    styles: {
        src: 'public/styles/less/*.less',
        dest: 'public/styles/gulp_css/'
    },
    scripts: {
        src: 'public/scripts/js/*.js',
        dest: 'public/scripts/gulp_js/'
    }
}

gulp.task("style", async () => {
    gulp.src(paths.styles.src)
    .pipe(less())                   // Обработать LESS
    .pipe(clean_css())              // Минификация CSS
    .pipe(gulp.dest(paths.styles.dest))
})

gulp.task("build", async () => {
    gulp.src(paths.scripts.src)
    .pipe(babel({presets: ["@babel/preset-env"]}))  // Обработать js
    .pipe(uglify())                                 // Минификация js
    .pipe(gulp.dest(paths.scripts.dest))
})

gulp.task('start', gulp.parallel('style', 'build'))
