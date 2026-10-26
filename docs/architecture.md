# MetaORM Architecture

## Purpose

MetaORM is a C++26 compile-time reflection-based ORM designed for strong type safety, low runtime mapping overhead, and multiple database backends.

## Core Design Decisions

### 1. Separate reflection from database execution

The ORM core discovers and maps C++ entities without depending on any database driver.

### 2. Pluggable database backends

Database adapters satisfy a common driver contract.

The initial PostgreSQL adapter integrates with Orbwvr. Future backends may use SQLite, MySQL, or other client libraries.

Database-specific SQL behavior must be isolated from generic query construction.

### 3. Compile-time versus runtime

Compile-time responsibilities:
- Entity field discovery
- Field names and types
- Entity metadata validation
- Type-specific binding and mapping generation
- SQL generation where practical

Runtime responsibilities:
- Database connections
- Parameter values
- Query execution
- Transactions
- Result retrieval

### 4. Public API

Expose a small, type-safe API. Keep internal implementation details hidden where practical.

### 5. Dependency direction

- ORM core must not depend on concrete database drivers.
- Database adapters depend on core contracts.
- Orbwvr does not depend on MetaORM.
- Core reflection functionality does not depend on Asio or libpq.

## Open Design Questions

These require investigation before implementation:

- Exact driver concept and execution interface
- Unified synchronous/asynchronous backend support
- Entity and column metadata representations
- Result materialization and ownership
- Query expression representation
- SQL dialect customization

Do not treat open design questions as finalized architecture.