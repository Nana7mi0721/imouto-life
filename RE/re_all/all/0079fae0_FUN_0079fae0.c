
void FUN_0079fae0(short *param_1,char *param_2,int param_3)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  uint uVar10;
  byte local_70 [16];
  short local_60 [16];
  short asStack_40 [16];
  undefined1 local_20 [32];
  
  iVar8 = 0;
  sVar2 = *(short *)(param_3 + 2);
  cVar1 = *param_2;
  iVar5 = *(int *)(param_3 + 8);
  if (0 < sVar2) {
    psVar9 = param_1;
    do {
      *psVar9 = (ushort)*(byte *)(iVar8 + (int)cVar1 * (int)sVar2 + iVar5) << 7;
      iVar8 = iVar8 + 1;
      psVar9 = psVar9 + 1;
    } while (iVar8 < *(short *)(param_3 + 2));
  }
  FUN_0079ef00(local_20,local_70,param_3,(int)*param_2);
  sVar2 = *(short *)(param_3 + 4);
  iVar5 = 0;
  iVar8 = *(short *)(param_3 + 2) + -1;
  if (-1 < iVar8) {
    psVar9 = asStack_40 + iVar8;
    while( true ) {
      uVar6 = param_2[iVar8 + 1] * 0x400;
      if ((int)uVar6 < 1) {
        if ((int)uVar6 < 0) {
          uVar6 = uVar6 + 0x66;
        }
      }
      else {
        uVar6 = uVar6 - 0x66;
      }
      iVar5 = ((int)uVar6 >> 0x10) * (int)sVar2 +
              ((int)((uint)local_70[iVar8] * (int)(short)iVar5) >> 8) +
              ((int)((uVar6 & 0xffff) * (int)sVar2) >> 0x10);
      iVar8 = iVar8 + -1;
      *psVar9 = (short)iVar5;
      if (iVar8 < 0) break;
      psVar9 = psVar9 + -1;
    }
  }
  FUN_007a0080(local_60,param_1,(int)*(short *)(param_3 + 2));
  iVar5 = 0;
  if (0 < *(short *)(param_3 + 2)) {
    do {
      uVar6 = (int)local_60[iVar5] << 0x10;
      if ((int)uVar6 < 1) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_007a22e0(uVar6);
        uVar10 = 0x20 - iVar8;
        iVar8 = 0x18 - uVar10;
        bVar3 = (byte)iVar8;
        if (iVar8 != 0) {
          if (iVar8 < 0) {
            uVar7 = uVar6 >> (bVar3 + 0x20 & 0x1f);
            uVar6 = uVar6 << (-bVar3 & 0x1f);
          }
          else {
            uVar7 = uVar6 << (0x20 - bVar3 & 0x1f);
            uVar6 = uVar6 >> (bVar3 & 0x1f);
          }
          uVar6 = uVar7 | uVar6;
        }
        uVar10 = (int)((-(uint)((uVar10 & 1) != 0) & 0xffffcb7a) + 0xb486) >>
                 ((byte)((int)uVar10 >> 1) & 0x1f);
        iVar8 = (int)(short)(((ushort)uVar6 & 0x7f) * 0xd5);
        iVar8 = ((int)uVar10 >> 0x10) * iVar8 + uVar10 + ((int)((uVar10 & 0xffff) * iVar8) >> 0x10);
      }
      iVar8 = ((int)asStack_40[iVar5] << 0xe) / iVar8 + (int)param_1[iVar5];
      if (iVar8 < 0x8000) {
        uVar4 = (ushort)iVar8 & (iVar8 < 0) - 1;
      }
      else {
        uVar4 = 0x7fff;
      }
      param_1[iVar5] = uVar4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(short *)(param_3 + 2));
  }
  FUN_0079fe40(param_1,*(undefined4 *)(param_3 + 0x20),(int)*(short *)(param_3 + 2));
  return;
}

