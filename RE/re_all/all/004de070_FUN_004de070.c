
void __fastcall FUN_004de070(int param_1)

{
  undefined4 *puVar1;
  _Container_proxy *p_Var2;
  undefined4 uVar3;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  puVar1 = (undefined4 *)FUN_004ce060(local_8);
  uVar3 = *puVar1;
  puVar1 = (undefined4 *)FUN_004cc870(local_c);
  FUN_004dda00(local_10,*puVar1,uVar3);
  p_Var2 = (_Container_proxy *)FUN_004e8ab0(*(undefined4 *)(param_1 + 4));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(param_1 + 2),p_Var2);
  p_Var2 = (_Container_proxy *)FUN_004d6870(*(undefined4 *)(param_1 + 4));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(param_1 + 2),p_Var2);
  p_Var2 = (_Container_proxy *)FUN_004d6880(*(undefined4 *)(param_1 + 4));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(param_1 + 2),p_Var2);
  deallocate(*(undefined4 *)(param_1 + 4),1);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

