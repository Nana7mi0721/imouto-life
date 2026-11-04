
undefined4 FUN_0056e8a0(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x864) == 0) {
    return 0xffffffff;
  }
  uVar1 = *(ushort *)(param_1 + 10);
  if (4 < uVar1) {
    piVar5 = (int *)(param_1 + 0x48);
    param_1 = 0;
    if (*(int *)(param_2 + 8) != 0) {
      piVar5 = (int *)(*piVar5 + *(int *)(param_2 + 0xc) + 0x20);
      do {
        if ((*(byte *)(piVar5 + -7) & 0x10) == 0) {
          iVar2 = piVar5[1];
          if (iVar2 != 0) {
            if ((*(ushort *)(iVar3 + 10) < 2) || (piVar5[2] == -1)) {
              iVar4 = iVar2;
            }
            else {
              iVar4 = piVar5[2];
            }
            FUN_0056e590(iVar4,0,iVar2,0,iVar3 + 0x858);
          }
        }
        else {
          FUN_0056e8a0(iVar3,*(int *)(iVar3 + 0x4c) + *piVar5);
        }
        param_1 = param_1 + 1;
        piVar5 = (int *)((int)piVar5 + (-(uint)(uVar1 < 2) & 0xfffffffc) + 0x2c);
      } while (param_1 < *(uint *)(param_2 + 8));
    }
  }
  return 0;
}

