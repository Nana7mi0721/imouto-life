
undefined4 __fastcall FUN_00524c30(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_00568b20(DAT_00a38de0 == 0,param_1);
  iVar7 = DAT_00a3ce54;
  if ((DAT_00a3d258 != 0) || (DAT_00a3d25c != 0)) {
    iVar2 = 0;
    iVar3 = -1;
    DAT_00a3ce50 = 0;
    DAT_00a3ce54 = -1;
    iVar5 = 3;
    do {
      iVar6 = 0;
      iVar4 = 0;
      if (0 < DAT_00a3ce44) {
        do {
          iVar1 = (&DAT_00a38e44)[iVar6];
          if (((iVar1 != 0) && (iVar4 = iVar4 + 1, *(int *)(iVar1 + 0x74) != 0)) &&
             (*(int *)(iVar1 + 8) == iVar5)) {
            if (iVar2 < 0x100) {
              (&DAT_00a3ce58)[iVar2] = iVar6;
              iVar2 = DAT_00a3ce50;
            }
            if (((*(int *)(iVar1 + 0x70) != iVar2) || (*(int *)(iVar1 + 0x78) == 1)) ||
               (iVar3 = iVar2, DAT_00a3d25c == 1)) {
              *(int *)(iVar1 + 0x70) = iVar2;
              *(undefined4 *)(iVar1 + 0x78) = 0;
              if (*(int *)(iVar1 + 0x74) != 0) {
                FUN_00568b40(iVar2,iVar1 + 8);
              }
              FUN_00568b60(*(undefined4 *)(iVar1 + 0x70),*(undefined4 *)(iVar1 + 0x74));
              iVar3 = DAT_00a3ce50;
            }
            iVar2 = iVar3 + 1;
            DAT_00a3ce50 = iVar2;
            DAT_00a3ce54 = iVar3;
          }
          iVar6 = iVar6 + 1;
        } while (iVar4 < DAT_00a3ce44);
      }
      iVar5 = iVar5 + -1;
    } while (0 < iVar5);
    iVar3 = iVar3 + 1;
    if (iVar3 <= iVar7) {
      do {
        FUN_00568b60(iVar3,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 <= iVar7);
    }
    DAT_00a3d258 = 0;
    DAT_00a3d360 = 1;
    DAT_00a3d25c = 0;
    FUN_00568bc0();
  }
  return 0;
}

