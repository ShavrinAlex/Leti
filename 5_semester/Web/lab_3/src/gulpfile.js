import gulp from "gulp"
import less from "gulp-less"
import clean_css from "gulp-clean-css"

// Настройка путей
const { src, dest } = gulp
const paths = { 
    styles: {
        src: 'public/styles/less/*.less',
        dest: 'public/styles/gulp_css/'
    }
}

export default () => {
    return src(paths.styles.src)
    .pipe(less())                   // Обработать LESS
    //.pipe(clean_css())              // Минификация CSS
    .pipe(dest(paths.styles.dest))
}
