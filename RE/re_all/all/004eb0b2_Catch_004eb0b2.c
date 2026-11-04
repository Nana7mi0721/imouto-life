
undefined4 Catch_004eb0b2(void)

{
  _Container_proxy *p_Var1;
  undefined1 *puVar2;
  int unaff_EBP;
  
  if (1 < *(int *)(unaff_EBP + -0x14)) {
    p_Var1 = (_Container_proxy *)FUN_004d6870(*(undefined4 *)(unaff_EBP + -0x18));
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(*(int *)(unaff_EBP + -0x28) + 2),p_Var1);
  }
  if (0 < *(int *)(unaff_EBP + -0x14)) {
    p_Var1 = (_Container_proxy *)FUN_004e8ab0(*(undefined4 *)(unaff_EBP + -0x18));
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(*(int *)(unaff_EBP + -0x28) + 2),p_Var1);
  }
  deallocate(*(undefined4 *)(unaff_EBP + -0x18),1);
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puVar2 = (undefined1 *)FUN_004e6d10(*(undefined4 *)(unaff_EBP + -0x18));
  *puVar2 = 1;
  puVar2 = (undefined1 *)FUN_004dd3c0(*(undefined4 *)(unaff_EBP + -0x18));
  *puVar2 = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}

