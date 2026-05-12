# LogCraft Playground

Open LogCraft playground content for [LogCraft](https://coderoast.fr/logcraft): starter scenarios, reusable agents, and the source of the small CLI consumer used to run scenarios locally when `logcraft_core` is available.

Explore realistic multi-agent log stream simulations — from simple microservices to complex distributed systems with chaos incidents, error cascading, and latency distributions.

This package is intentionally source-visible. The CLI links against `logcraft_core`, which is a closed-source package, so users without that dependency can still read and change the CLI/scenario sources but cannot build the CLI binary from this repository alone. Cross-repo status and compatibility live in [../technical_docs/README.md](../technical_docs/README.md) and [../technical_docs/ROADMAP.md](../technical_docs/ROADMAP.md).

**Use these scenarios as:**
- Learning resources to understand LogCraft's capabilities
- Templates to build your own simulations
- Reference implementations for common architectures
- A playground CLI entry point when built inside the full CodeRoast workspace

## Key Paths

| Path | Purpose |
|---|---|
| `scenario/01_starter/` | LogCraft Playground starter scenario YAML. |
| `scenario/agents/` | Reusable agent definitions and templates. |
| `cli/` | Source for the LogCraft playground CLI consumer; links with `logcraft_core`. |
| `scenario_reference.md` | Scenario DSL reference mirrored from LogCraft-facing docs. |

## Build

Inside the full CodeRoast workspace, use `malf` from this package root:

```bash
malf build .
```

The build requires `logcraft_core/1.3.3`. Scenario YAML remains editable and inspectable without that dependency.
