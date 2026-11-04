
void FUN_0079c3a0(int param_1,short *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  if (*(int *)(param_1 + 0x1040) != 0) {
    FUN_0079f490(param_1 + 0x1084,param_1 + 0x1088,param_2,param_3);
    *(undefined4 *)(param_1 + 0x1078) = 1;
    return;
  }
  if (*(int *)(param_1 + 0x1078) != 0) {
    FUN_0079f490(&local_8,&local_4,param_2,param_3);
    iVar2 = *(int *)(param_1 + 0x1088);
    if (iVar2 < local_4) {
      *(int *)(param_1 + 0x1084) =
           *(int *)(param_1 + 0x1084) >> ((char)local_4 - (char)iVar2 & 0x1fU);
    }
    else if (local_4 < iVar2) {
      local_8 = local_8 >> ((char)iVar2 - (char)local_4 & 0x1fU);
    }
    iVar2 = *(int *)(param_1 + 0x1084);
    if (iVar2 < local_8) {
      if (iVar2 == 0) {
        iVar2 = 0x20;
      }
      else {
        iVar2 = FUN_007a22e0(iVar2);
        iVar2 = 0x20 - iVar2;
      }
      iVar6 = *(int *)(param_1 + 0x1084) << ((byte)(iVar2 + -1) & 0x1f);
      iVar2 = 0x18 - (iVar2 + -1);
      *(int *)(param_1 + 0x1084) = iVar6;
      local_8 = local_8 >> ((iVar2 < 1) - 1U & (byte)iVar2 & 0x1f);
      iVar2 = local_8;
      if (local_8 < 2) {
        iVar2 = 1;
      }
      uVar3 = iVar6 / iVar2;
      if ((int)uVar3 < 1) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_007a22e0(uVar3);
        uVar5 = 0x20 - iVar2;
        iVar2 = 0x18 - uVar5;
        bVar1 = (byte)iVar2;
        if (iVar2 != 0) {
          if (iVar2 < 0) {
            uVar4 = uVar3 >> (bVar1 + 0x20 & 0x1f);
            uVar3 = uVar3 << (-bVar1 & 0x1f);
          }
          else {
            uVar4 = uVar3 << (0x20 - bVar1 & 0x1f);
            uVar3 = uVar3 >> (bVar1 & 0x1f);
          }
          uVar3 = uVar4 | uVar3;
        }
        uVar5 = (int)((-(uint)((uVar5 & 1) != 0) & 0xffffcb7a) + 0xb486) >>
                ((byte)((int)uVar5 >> 1) & 0x1f);
        iVar2 = (int)(short)(((ushort)uVar3 & 0x7f) * 0xd5);
        iVar2 = ((int)uVar5 >> 0x10) * iVar2 + uVar5 + ((int)((uVar5 & 0xffff) * iVar2) >> 0x10);
      }
      iVar6 = 0;
      if (0 < param_3) {
        uVar3 = iVar2 * 0x10;
        do {
          uVar5 = uVar3 + ((iVar2 * -0x10 + 0x10000) / param_3) * 4;
          *param_2 = (short)((uVar3 & 0xffff) * (int)*param_2 >> 0x10) +
                     (short)(uVar3 >> 0x10) * *param_2;
          if (0x10000 < (int)uVar5) break;
          iVar6 = iVar6 + 1;
          param_2 = param_2 + 1;
          uVar3 = uVar5;
        } while (iVar6 < param_3);
      }
    }
  }
  *(undefined4 *)(param_1 + 0x1078) = 0;
  return;
}

