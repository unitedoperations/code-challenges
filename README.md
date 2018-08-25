# UO Community Coding Challenges

Private community challenges will be created and hosted on the [CodeSignal](https://codesignal.com) platform every so often and this repository will serve as a place for the challenge solutions to be uploaded for reference _**1 week**_ after the challenge has been posted.

The platform provides an IDE for countless languages and the challenge creator will provide unit test cases for the challenge to run against. Once you are confident in your solution and the test cases are successful, first submit your solution to the challenge on [CodeSignal](https://codesignal.com), and then _optionally_ submit them to this repository using the guidelines below.

If you do not have an account on [CodeSignal](https://codesignal.com), you can register at their website or login with your GitHub account.

## Repository Submissions _(optional)_

Challenge solutions must be submitted as pull requests that will be approved by the repository owners.

For each challenge, a user's submission will be in a sub-directory using their UO username.

> _**Example**_\
> My submission for challenge 1 on this repository would be in the file structure like...
>
> ```
> code-challenges
>   |- 1
>   | |- Synxe
>   |   |- solution.cpp
>   |- ...
> ```

### Creating a Pull Request

Assuming you have a GitHub account, you may submit the pull request one of two ways.

#### Fork _(preferred)_

1. Create a fork of the repository to your own account and create a new branch with the naming convention:\
   `$ git checkout -b sol/USERNAME`
2. Use the guideline above to put your solution code in the challenge directory
3. Run the following commands to push the code into you forked branch:

```sh
$ git add -A
$ git commit -m 'challenge X solution'
$ git push origin sol/USERNAME
```

4. Submit the pull request using the button on _this_ (the original) repository.

#### Clone

1. Create a direct clone of this repository:\
   `$ git clone https://github.com/unitedoperations/code-challenges.git`
2. Create a new branch for your username:\
   `$ git checkout -b sol/USERNAME`
3. _Steps 2-4 of the `Fork` steps_...

After creating a pull request with your solution for the challenge, it will be reviewed and merged once a repository owner approves it.

## Contact

_If you have any questions or challenge suggestions contact [Synxe](https://github.com/callensm)._
