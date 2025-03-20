<?php

namespace App\Bundle\E03Bundle\Form;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\Extension\Core\Type\PasswordType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\Form\Extension\Core\Type\TextareaType;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\Validator\Constraints\Length;
use Symfony\Component\Validator\Constraints\NotBlank;
use Symfony\Component\Validator\Constraints\Regex;

class PostForm extends AbstractType{

	public function buildForm(FormBuilderInterface $builder, array $options): void
	{ 
		$builder
		->add('title', TextType::class, [
			'constraints' => [
				new NotBlank([
					'message' => 'Title cannot be empty.',
				]),
				new Length([
					'min' => 3,
					'max' => 40,
					'minMessage' => 'Title must be at least {{ limit }} characters long.',
					'maxMessage' => 'Title cannot be longer than {{ limit }} characters.',
				])
			]
		])
		->add('content', TextareaType::class, [
			'constraints' => [
				new NotBlank([
					'message' => 'Post content cannot be empty.',
				]),
				new Length([
					'min' => 20,
					'max' => 50000,
					'minMessage' => 'Post content must be at least {{ limit }} characters long.',
					'maxMessage' => 'Post content cannot be longer than {{ limit }} characters.',
				])
			]
		])
		->add('submit', SubmitType::class)
		;
	}
}
