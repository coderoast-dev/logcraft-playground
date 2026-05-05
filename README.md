# LogCraft Scenario Library

A curated collection of production-ready scenario templates for [LogCraft](https://coderoast.fr/logcraft).

Explore realistic multi-agent log stream simulations — from simple microservices to complex distributed systems with chaos incidents, error cascading, and latency distributions.

The scenario library is data, not engine code. LogCraft owns the scenario DSL reference in [../logcraft/technical_docs/reference/scenario_reference.md](../logcraft/technical_docs/reference/scenario_reference.md). Cross-repo status and compatibility live in [../technical_docs/README.md](../technical_docs/README.md) and [../technical_docs/ROADMAP.md](../technical_docs/ROADMAP.md).

**Use these scenarios as:**
- Learning resources to understand LogCraft's capabilities
- Templates to build your own simulations
- Reference implementations for common architectures
- Regression test suites for your observability stack

## Key Paths

| Path | Purpose |
|---|---|
| `scenario/` | Runnable scenario YAML. |
| `agents/` | Reusable agent definitions and templates. |
| `scenario/self_hosted/` | Scenarios that require local filesystem includes or registry support. |
| `scenario_reference.md` | Scenario DSL reference mirrored from LogCraft-facing docs. |
