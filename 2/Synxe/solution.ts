function removeOldMissions(missions: string[]): string[] {
  const cache: { [k: string]: RegExpExecArray } = {}
  const exps = missions.map(m => /^(CO|TVT|COTVT|LOL)(\d+)_([a-zA-Z_]+)_V(\d+)\.pbo$/g.exec(m))

  for (const e of exps) {
    if (!e) continue
    const version = parseInt(e[4])
    const key = `${e[1]}${e[2]}${e[3]}`

    if (!cache[key] || parseInt(cache[key][4]) < version) {
      cache[key] = e
    }
  }

  const purged: string[] = Object.values(cache).map(v => v[0])
  const countPattern: RegExp = /^(?:CO|TVT|COTVT|LOL)(\d+)/
  purged.sort((x, y) => parseInt(countPattern.exec(x)[1]) - parseInt(countPattern.exec(y)[1]))
  return purged
}
