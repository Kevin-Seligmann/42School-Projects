<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Routing\Attribute\Route;
use App\Form\Type\FormType;
use App\Entity\Form;
use App\Service\TargetFileProvider;

class FormController extends AbstractController
{
    #[Route('/e02', name: 'form')]
    public function index(Request $request, TargetFileProvider $targetFileProvider): Response
    {
		$targetFile = $targetFileProvider->getTargetFile(); 
		
		$formData = new Form();

		$form = $this->createForm(FormType::class, $formData);

		$form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
			$formData = $form->getData();
			
			$fileContent = $formData->getMessage();
			if ($formData->getPutDate())
				$fileContent .= " - Timestamp: ".time();
			$fileContent .= "\n";
			
			file_put_contents($this->getParameter('kernel.project_dir')."/".$targetFile, $fileContent, FILE_APPEND);

			return $this->render("form/form.html.twig", [
				'writenText' => $fileContent,
				'form' => $form,
			]);
        }

		return $this->render("form/form.html.twig", [
			'form' => $form,
		]);
    }
}
