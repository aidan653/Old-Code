function calcCirclePosition() {
		var div1circ = $("#outer-circle")[0].getBoundingClientRect();
		var div1center = (div1circ.left + div1circ.width) / 2;
		var div1right = div1circ.width;
		var radiusOFF = div1right - div1center;
		//Correction to make it inline with circle. Subtracting the width of the .room element to make it center.
		var radius = radiusOFF - 400;
		var elements = 4;
		var odd = elements%2;
		var slice = 74;
		var spacing =  (slice/2)/elements;
		var oddSpacing = slice/elements;
		var oddStart = -(slice/2) + oddSpacing/2;
		var evenStart = (slice/2)/(elements);
		const rotations = [];
		const counterRotations = [];
		var elemCounter = -1;
		var rotate;
		if(odd==0) {
			for (var i = 1; i < elements / 2 + 1; i++) {
				if (i == 1) {
					rotate = spacing;
				} else {
					rotate = evenStart + (spacing * i);
					evenStart += evenStart;
				}
				rotateReverse = rotate * -1;
				elemCounter++;
				rotations[elemCounter] = rotate;
				counterRotations[elemCounter] = rotateReverse;
				elemCounter++;
				rotations[elemCounter] = rotate * -1;
				counterRotations[elemCounter] = rotateReverse * -1;
				if (i == elements / 2) {
					for (var i = 1; i < elements / 2 + 1; i++) {
						$('<div/>', {
							'class': 'room',
							'title': i,
							'style': 'transform: ' + 'rotate(' + rotations[rotations.length - 1] + 'deg) translate(' + radius + 'px) rotate(' + counterRotations[rotations.length - 1] + 'deg) translateY(-50px);'
						}).appendTo('#outer-circle');

						$('<div/>', {
							'class': 'room',
							'title': i + 'negative',
							'style': 'transform: ' + 'rotate(' + rotations[rotations.length - 1] + 'deg) translate(' + radius + 'px) rotate(' + counterRotations[rotations.length - 1] + 'deg) translateY(-50px);'
						}).appendTo('#outer-circle');
					}
				}
			}
			$('.room').each(function(index, element) {
				$(element).animate({ //Can't directly rotate with jQuery, but if you animate something that simply doesn't do anything, you can still use the step function which activates every animation call, adding some delay to the transition which makes it so you can actually see the transition.
					rotate: rotations[index]
				}, {
					step: function(now,fx) {
						$(element).css({'transform': 'rotate(' + rotations[index] + 'deg) translate(' + radius + 'px) rotate(' + counterRotations[index] + 'deg) translateY(-50px)'});
					},
					duration: 1000,
					easing: 'linear'
				});
			});
		} else {
			for(var i = 1; i < elements + 1; i++) {
				if (i==1) {
					rotate = oddStart;
				} else {
					rotate = oddStart + oddSpacing;
					oddStart += oddSpacing;
				}
				rotateReverse = rotate * -1;
				elemCounter++;
				rotations[elemCounter] = rotate;
				counterRotations[elemCounter] = rotateReverse;
				elemCounter++;
				rotations[elemCounter] = rotate * -1;
				counterRotations[elemCounter] = rotateReverse * -1;
				if (i == elements) {
					for (var i = 1; i < elements + 1; i++) {
						$('<div/>', {
							'class': 'room',
							'title': i,
							'style': 'transform: ' + 'rotate(' + rotations[rotations.length - 1] + 'deg) translate(' + radius + 'px) rotate(' + counterRotations[rotations.length - 1] + 'deg) translateY(-50px);'
						}).appendTo('#outer-circle');
					}
				}
			}
			$('.room').each(function(index, element) {
				$(element).animate({
					rotate: rotations[index]
				}, {
					step: function(now,fx) {
						$(element).css({'transform': 'rotate(' + rotations[index] + 'deg) translate(' + radius + 'px) rotate(' + counterRotations[index] + 'deg) translateY(-50px)'});
					},
					duration: 1000,
					easing: 'linear'
				});
			});
		}
	}