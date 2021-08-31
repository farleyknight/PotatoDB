

# Adding B-Trees

While working on B-Trees, I'm hitting some other issues:

* The metadata for tables is kept in a separate table altogether
  - This was fine to start, but I'm realizing it's not a good pattern
  - I don't want to copy this pattern for indexes
  - NEW DESIGN [DONE]:
    - The first block of every table file has the metadata for that table.
    - Merge TableMgr into FileMgr.
    - SystemCatalog should NOT use DB queries, but instead hold metadata from table directly.
    - All stuff about the system catalog is held in memory.
    - Allowing SQL to query the system catalog is something we need to figure out in time
    - This should SPEED UP the time it takes to load the system catalog.
  - Verifying NEW DESIGN:
    - Will need to start writing *unit tests* for TableHeaderPage
      - Need to verify that writing a schema and then reading from it yields the same result.
    - NEW CLASS - IndexHeaderPage
      - Need implementation of this

