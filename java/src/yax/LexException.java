/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

//////////////////////////////////////////////////

package yax;

public class LexException extends java.lang.Exception
{
    public LexException(String msg) {super(msg);}
    public LexException(Throwable e) {super(e);}
    public LexException(String msg, Throwable e) {super(msg,e);}
}
