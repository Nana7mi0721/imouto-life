
/* Library Function - Single Match
    public: struct _Ctypevec __thiscall std::_Locinfo::_Getctype(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

_Ctypevec * __thiscall std::_Locinfo::_Getctype(_Locinfo *this,_Ctypevec *__return_storage_ptr__)

{
  short *psVar1;
  int iVar2;
  wchar_t *pwVar3;
  _Ctypevec *p_Var4;
  _Ctypevec local_24 [2];
  
  p_Var4 = __Getctype(local_24);
  psVar1 = p_Var4->_Table;
  iVar2 = p_Var4->_Delfl;
  pwVar3 = p_Var4->_LocaleName;
  __return_storage_ptr__->_Page = p_Var4->_Page;
  __return_storage_ptr__->_Table = psVar1;
  __return_storage_ptr__->_Delfl = iVar2;
  __return_storage_ptr__->_LocaleName = pwVar3;
  return __return_storage_ptr__;
}

