# To clone a remote git repository to a local repository in the local pc:
 cd /h/GitHubLocalRepository
 git clone https://github.com/JariMutikainen/geeksExercises.git

# To update the local copy of the origin/master to be identical to the
# remote origin/master:
 git fetch -t # -t = 'with the tags included'.
# At this point the origin/master in the local repository = origin/master in
# the remote repository.
 git checkout master # Goto the master branch in the local repository
 git log -20 --graph --decorate --oneline master # Show the last 20 commits.
 git log -20 --graph --decorate --oneline origin/master 
# ToinenKokeilussa tehty rivi.
 git merge origin/master # In the local repo merge origin/master into master.

# To start a new development branch named jari/readme from the commit
# that the origin/master-label is pointing at in the local repository:
git checkout -b jari/readme origin/master # -b = 'branch'.

git status
git add --all # To add changes from the working area into the stage
git commit -m "Added new text into the readme.txt file." # -m = 'message'
git status
git branch -a # -a = 'show all the branches - i.e. both local and remote.'
git push -u origin jari/readme # -u = 'upstream'. -u is needed only at the
                               # first push of a brand new branch.

# The development branch is merged into the origin/master branch in the
# remote repository using the FireFox browser. Once the merge has been
# completed the development branch (= origin/jari/readme) in the remote 
# repository can be deleted. This is also done in the FireFox browser. 

# To update the local repository to match the current contents of the remote
# repository do a fetch. Use the '--prune' option to stop the git from showing
# the remote branch origin/jari/readme, which no longer exists.

git fetch -t --prune 
git checkout master # jump into the master branch in the local repository.
git merge origin/master # merge origin/master into master in the local repo.
# Now that the contents of the jari/readme branch has been incorporated into
# the master branch in the FireFox browser the local jari/readme can be 
# deleted in the local repository.
git branch -a
git branch -d jari/readme

# Consider the case in which other designers have made changes to the 
# origin/master branch in the remote repository. In that case you may want
# to include those changes to your development branch. You can do this
# by rebasing your local development branch to the newest commit of the
# origin/master. These are the steps you need to take.
