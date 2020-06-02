recursiverm() {
  for d in *; do
    if [ -d "$d" ]; then
      (cd -- "$d" && recursiverm)
          VAR=$(find $PWD/$d -type f -iname "mem.txt")
	  #echo $VAR
          if [ -n "$VAR" ]; then
            echo found
          else $PWD/$d
          fi
          #"$@"
    fi
  done
}

recursiverm
