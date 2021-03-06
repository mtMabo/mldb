import datetime

from mldb import mldb

ds1 = mldb.create_dataset({
    'type': 'sparse.mutable',
    'id': 'dataset1'})

for i in range(3):
    ds1.record_row('row_' + str(i),
                   [['x', i, 0]])
ds1.commit()

#Despite this being an optimized path, we dont test for time because for 1M row its *only*
#2 or 3 times faster and this would make the unit test too slow
#but we do want a test for correctness
res = mldb.get('/v1/query', q="SELECT * FROM dataset1 WHERE (x IS NOT null) AND rowName() != 'row_1' order by rowName() desc")

expected = [
    {
        "rowName": "row_2",
        "columns": [
            [
                "x",
                2,
                "1970-01-01T00:00:00Z"
            ]
        ]
    },
    {
        "rowName": "row_0",
        "columns": [
            [
                "x",
                0,
                "1970-01-01T00:00:00Z"
            ]
        ]
    }
]

assert res.json() == expected;

request.set_return('success')
