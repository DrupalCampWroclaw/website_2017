(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
    Drupal.behaviors.hide_profile_fields = {
        attach: function(context, settings) {

            var languages = [
                "en",
                "pl",
                "und"
            ];

            $.each(languages, function(index, value){

            $("input[name='field_attendance[" + value + "][no]']").live('click', function(){

                $('.form-item-field-attendance-'+ value +'-friday').toggle("slow");
                $('.form-item-field-attendance-'+ value +'-saturday').toggle("slow");
                $('.form-item-field-attendance-'+ value +'-sunday').toggle("slow");

                $('input:checkbox[value=friday]').attr('checked',false);
                $('input:checkbox[value=saturday]').attr('checked',false);
                $('input:checkbox[value=sunday]').attr('checked',false);

            });

            if($("#edit-field-attendance-"+ value +"-no").is(':checked')) {

                $('.form-item-field-attendance-'+ value +'-friday').hide();
                $('.form-item-field-attendance-'+ value +'-saturday').hide();
                $('.form-item-field-attendance-'+ value +'-sunday').hide();

            }

            });

        }
    };


})(jQuery, Drupal, this, this.document);