
void FUN_004eadb0(void)

{
  wchar_t *pwVar1;
  int unaff_EBP;
  undefined4 uVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    pwVar1 = FID_conflict__Myptr(*(void **)(unaff_EBP + -0x1c));
    copy(*(undefined4 *)(unaff_EBP + -0x14),pwVar1,uVar2);
  }
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),true,0);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 0x18) = *(undefined4 *)(unaff_EBP + -0x18);
  FID_conflict__Eos(*(void **)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

