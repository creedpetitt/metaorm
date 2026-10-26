# MetaORM Roadmap

## Current Phase: Foundation

- [ ] Establish CMake project and compiler configuration
- [ ] Verify native C++26 reflection support
- [ ] Implement basic compile-time field discovery
- [ ] Implement generic field visitation
- [ ] Test reflection with multiple entity types

## Next Phase: Core Design

- [ ] Design entity metadata representation
- [ ] Design logical database value types
- [ ] Define driver contract
- [ ] Define SQL dialect responsibilities
- [ ] Document ownership and lifetime requirements

## Later Phases

- PostgreSQL integration through Orbwvr
- Generic entity INSERT and SELECT
- Result-to-entity materialization
- UPDATE and DELETE
- Compile-time validation and annotations
- Type-safe queries
- SQLite backend
- Advanced ORM functionality

## Development Rules

Complete one focused milestone at a time.

Update this roadmap when milestones are verified.

Do not mark functionality complete without appropriate compilation and testing.

Do not implement future phases unless explicitly requested.
