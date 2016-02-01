IF we have an exception like this:
```
	if (p < 0 || p > size)
		throw std::out_of_range("\nInvalid index\n");
```
		
And a catch like this in our test file:

```
catch (exception e) {
        cout << "Exception: " << e.what() << endl;
  }
```

And try an exception, this is what we get in the terminal: 

```
Exception: std::exception
```

As you can see, we don't see the "Invalid Index" message. But, if we reference the exception, like this:

```
catch (exception &e) {
        cout << "Exception: "" << e.what() << endl;
```

Then we get this:

'''
Exception:
Invalid index
'''

Which is what we want. 

The question is, should the test file contain the "&" (for exception e) or not? It was not in the test that was provided to us. Was it a mistake? Or is there another way to do it?
