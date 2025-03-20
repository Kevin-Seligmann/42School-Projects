<?php

namespace App\Command;

use Exception;
use Ratchet\Http\HttpServer;
use Ratchet\MessageComponentInterface;
use Ratchet\WebSocket\WsServer;
use Symfony\Component\Console\Attribute\AsCommand;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Ratchet\Server\IoServer;
use Ratchet\ConnectionInterface;

#[AsCommand(
    name: 'websocket:server',
    description: 'Opens a websocket server on port 8080',
    hidden: false
)]
class WebsocketCommand extends Command {
	protected function execute(InputInterface $input, OutputInterface $output): int
	{
		$output->writeln([
			'Opening websocket on port 8080...',
			'============',
			'',
		]);
	
		try {
			$server = IoServer::factory(
				new HttpServer(
					new WsServer(new WebsocketApp())
				),
				8080,
				'0.0.0.0'
			);
			$server->run();
		} catch (Exception $e){
			$output->writeln('Couldn\'t run websocket server: '.$e->getMessage());
			return Command::FAILURE;
		}

		$output->writeln("Websocket server closed");
		return Command::SUCCESS;
	}
}

class WebsocketApp implements MessageComponentInterface {
	protected $clients;

    public function __construct() {
		echo "Websocket server running...\n";
        $this->clients = new \SplObjectStorage;
    }

	public function onOpen(ConnectionInterface $conn) {
		$this->clients->attach($conn);
	
        echo "New connection! ({$conn->resourceId})\n";
    }

    public function onMessage(ConnectionInterface $from, $msg) {
		$numRecv = count($this->clients) - 1;
        echo sprintf('Connection %d sending message "%s" to %d other connection%s' . "\n"
            , $from->resourceId, $msg, $numRecv, $numRecv == 1 ? '' : 's');
		$data = json_decode($msg, true);
		$response = json_encode( []);
		if (isset($data['type']) && $data['type'] === 'deletePost'){
			$response = json_encode($data);
			$this->sendResponseAll($from, $response);
		}
		if (isset($data['type']) && $data['type'] === 'addPost'){
			$response = json_encode($data);
			$this->sendResponseAll($from, $response);
		}
	}

	private function sendResponseAll(ConnectionInterface $from, $response){
		foreach ($this->clients as $client)
			if ($from !== $client)
				$client->send($response);
	}

    public function onClose(ConnectionInterface $conn) {
		$this->clients->detach($conn);

        echo "Connection {$conn->resourceId} has disconnected\n";
    }

    public function onError(ConnectionInterface $conn, \Exception $e) {
		echo "An error has occurred: {$e->getMessage()}\n";

        $conn->close();
    }
}
