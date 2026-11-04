
void FUN_005a7ce0(void)

{
  int iVar1;
  int in_EAX;
  
  if ((((DAT_00a37dc8 != 0) && (DAT_00a381c0 != 0)) && (DAT_00a381c4 != 0)) &&
     (*(int *)(&DAT_007da3a8 + in_EAX * 4) == 0)) {
    FUN_0059b720(DAT_00e02d7c,1);
    FUN_0059b660((&DAT_00e398f4)[in_EAX]);
    return;
  }
  iVar1 = *(int *)(&DAT_007da380 + in_EAX * 4);
  if (DAT_00f3a04c != 0) {
    FUN_0059b660(0);
    if ((DAT_00e80614 != iVar1) || (DAT_00e39a54 != 0)) {
      FUN_005d3bf0(iVar1);
      DAT_00e80614 = iVar1;
    }
  }
  return;
}

