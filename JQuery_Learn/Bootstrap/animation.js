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

// $(window).on('scroll', function(){
//     $('.nav-munu').addClass('nav-black');
// })

// $(window).on('scroll', function(){
//     if($(window).scrollTop() > 200) {
//         $('.nav-munu').addClass('nav-black');
//         //$('.nav-munu h4').addClass('small-logo');
//     }
// })

$(window).on('scroll',function(){
    if($(window).scrollTop()>=200){
        $('.nav-menu').css({backgroundColor:'black', color:'white'});
        $('.nav-menu').css("font-size", "10px")
    }
    if($(window).scrollTop()<200){
        $('.nav-menu').css({backgroundColor:'white', color:'black'})
        $('.nav-menu').css("font-size", "18px")
    }
})
