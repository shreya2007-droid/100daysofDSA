start="2026-02-04"
end="2026-05-04"

current="$start"

while true; do
  echo "update $current" >> log.txt
  git add .

  GIT_AUTHOR_DATE="$current 12:00:00" \
  GIT_COMMITTER_DATE="$current 12:00:00" \
  git commit -m "Update on $current"

  # Break condition
  if [[ "$current" == "$end" ]]; then
    break
  fi

  # Move to next day
  current=$(date -j -v+1d -f "%Y-%m-%d" "$current" +"%Y-%m-%d")
done

git push origin main
