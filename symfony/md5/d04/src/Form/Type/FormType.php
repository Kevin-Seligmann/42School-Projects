<?php

namespace App\Form\Type;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\Extension\Core\Type\ChoiceType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\Validator\Constraints\NotBlank;

class FormType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options): void
    {
        $builder
            ->add('message', TextType::class, [
                'constraints' => new NotBlank()
            ])
            ->add('putDate', ChoiceType::class, [
                'choices' => [
                    'Yes' => true,
                    'No' => false,
                ],
                'label' => 'Include timestamp '
            ])
            ->add('submit', SubmitType::class)
        ;
    }
}
