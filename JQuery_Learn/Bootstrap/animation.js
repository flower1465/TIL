$('.slide-1').on('click', function(){
    $('.slide-container').css('transform', 'translateX(0vw)');
})

$('.slide-2').on('click', function(){
    $('.slide-container').css('transform', 'translateX(-100vw)');
})

$('.slide-3').on('click', function(){
    $('.slide-container').css('transform', 'translateX(-200vw)');
})

$('.slide-4').on('click', function(){
    $('.slide-container').css('transform', 'translateX(-300vw)');
})

var show = 1;
$('.slide-next').on('click', function(){
    if (show == 3){
        $('.slide-contalner').css('transform', 'translateX(-100vw)');
        show = show - 1;
    } else if (show == 2){
        $('.slide-contalner').css('transform', 'translateX(0vw)');
        show = show - 1;
    }
});