
/* Library Function - Single Match
    protected: void __thiscall std::basic_filebuf<char,struct std::char_traits<char> >::_Init(struct
   _iobuf *,enum std::basic_filebuf<char,struct std::char_traits<char> >::_Initfl)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::_Init
          (basic_filebuf<char,std::char_traits<char>_> *this,_iobuf *param_1,_Initfl param_2)

{
  this[0x54] = (basic_filebuf<char,std::char_traits<char>_>)(param_2 == 1);
  this[0x4c] = (basic_filebuf<char,std::char_traits<char>_>)0x0;
  basic_streambuf<char,std::char_traits<char>_>::_Init
            ((basic_streambuf<char,std::char_traits<char>_> *)this);
  if (param_1 != (_iobuf *)0x0) {
    basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)this,&param_1->_base,&param_1->_ptr,
               &param_1->_cnt,&param_1->_base,&param_1->_ptr,&param_1->_cnt);
  }
  *(_iobuf **)(this + 0x58) = param_1;
  *(undefined4 *)(this + 0x50) = DAT_00a1fba8;
  *(undefined4 *)(this + 0x40) = DAT_00a1fba8;
  *(undefined4 *)(this + 0x3c) = 0;
  return;
}

