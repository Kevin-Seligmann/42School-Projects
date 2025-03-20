<?php

namespace App\Bundle\E01Bundle\Form;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\Extension\Core\Type\PasswordType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\Validator\Constraints\Length;
use Symfony\Component\Validator\Constraints\NotBlank;
use Symfony\Component\Validator\Constraints\Regex;

class RegisterForm extends AbstractType{

	public function buildForm(FormBuilderInterface $builder, array $options): void
	{ 
		$builder
		->add('username', TextType::class, [
			'constraints' => [
				new NotBlank([
					'message' => 'Username cannot be empty.',
				]),
				new Length([
					'min' => 3,
					'max' => 20,
					'minMessage' => 'Username must be at least {{ limit }} characters long.',
					'maxMessage' => 'Username cannot be longer than {{ limit }} characters.',
				]),
				new Regex([
					'pattern' => '/^[a-zA-Z0-9_]+$/',
					'message' => 'Username can only contain letters, numbers, and underscores.',
				])
			]
		])
		->add('password', PasswordType::class, [
			'constraints' => [
				new NotBlank([
					'message' => 'Password cannot be empty.',
				]),
				new Length([
					'min' => 8,
					'max' => 20,
					'minMessage' => 'Password must be at least {{ limit }} characters long.',
					'maxMessage' => 'Password cannot be longer than {{ limit }} characters.',
				]),
				new Regex([
					'pattern' => '/^(?=.*[A-Za-z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]+$/',
					'message' => 'Password must contain at least one letter, one number, and one special character.',
				])
			]
		])
		->add('submit', SubmitType::class)
		;
	}
}
