
void __thiscall FUN_004ea0e0(int param_1,_Container_proxy *param_2)

{
  _Container_proxy *p_Var1;
  char *pcVar2;
  undefined4 *puVar3;
  _Container_proxy *local_8;
  
  local_8 = param_2;
  while( true ) {
    pcVar2 = (char *)FUN_004e0e80(local_8);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_004d6880(local_8);
    FUN_004ea0e0(*puVar3);
    puVar3 = (undefined4 *)FUN_004e8ab0(local_8);
    p_Var1 = (_Container_proxy *)*puVar3;
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(param_1 + 1),local_8);
    deallocate(local_8,1);
    local_8 = p_Var1;
  }
  return;
}

