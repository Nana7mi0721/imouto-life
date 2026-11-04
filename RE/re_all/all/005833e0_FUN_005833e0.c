
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_005833e0(int param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined1 uVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char acStack_1401 [1021];
  int aiStack_1004 [1024];
  undefined4 uStack_4;
  
  uStack_4 = 0x5833ea;
  if (param_1 == 0) {
    param_1 = *param_2;
  }
  iVar2 = *(int *)(param_1 + 8);
  if ((**(uint **)(param_1 + 0x21c) & *(uint *)(*(int *)(param_1 + 0x218) + 0xc)) == 0) {
    if (param_2 != (int *)0x0) {
      if (*(char *)(param_1 + 0x269) == '\0') {
        if (*(char *)((int)param_2 + 0x15) != '\0') {
          param_2[0x18] = param_2[6];
          param_2[0x19] = param_2[7];
          param_2[0x1a] = param_2[8];
          param_2[0x1b] = param_2[9];
          param_2[0x1c] = param_2[10];
          param_2[0x1d] = param_2[0xb];
          param_2[0x1e] = param_2[0xc];
          param_2[0x1f] = param_2[0xd];
          param_2[0x20] = param_2[0xe];
          param_2[0x21] = param_2[0xf];
          param_2[0x22] = param_2[0x10];
          param_2[0x23] = param_2[0x11];
          param_2[0x24] = param_2[0x12];
          param_2[0x25] = param_2[0x13];
          param_2[0x26] = param_2[0x14];
          param_2[0x27] = param_2[0x15];
        }
        *(char *)((int)param_2 + 0x5d) = *(char *)((int)param_2 + 0x15);
      }
      else if (*(char *)((int)param_2 + 0x15) == '\0') {
        param_2[0x18] = *(int *)(param_1 + 0x26c);
        param_2[0x19] = *(int *)(param_1 + 0x270);
        param_2[0x1a] = *(int *)(param_1 + 0x274);
        param_2[0x1b] = *(int *)(param_1 + 0x278);
        param_2[0x1c] = *(int *)(param_1 + 0x27c);
        param_2[0x1d] = *(int *)(param_1 + 0x280);
        param_2[0x1e] = *(int *)(param_1 + 0x284);
        param_2[0x1f] = *(int *)(param_1 + 0x288);
        param_2[0x20] = *(int *)(param_1 + 0x28c);
        param_2[0x21] = *(int *)(param_1 + 0x290);
        param_2[0x22] = *(int *)(param_1 + 0x294);
        param_2[0x23] = *(int *)(param_1 + 0x298);
        param_2[0x24] = *(int *)(param_1 + 0x29c);
        param_2[0x25] = *(int *)(param_1 + 0x2a0);
        param_2[0x26] = *(int *)(param_1 + 0x2a4);
        param_2[0x27] = *(int *)(param_1 + 0x2a8);
        *(undefined1 *)((int)param_2 + 0x5d) = 1;
      }
      else {
        param_2[0x18] = (int)(*(float *)(param_1 + 0x26c) * (float)param_2[6]);
        param_2[0x19] = (int)(*(float *)(param_1 + 0x270) * (float)param_2[7]);
        param_2[0x1a] = (int)(*(float *)(param_1 + 0x274) * (float)param_2[8]);
        param_2[0x1b] = (int)(*(float *)(param_1 + 0x278) * (float)param_2[9]);
        param_2[0x1c] = (int)(*(float *)(param_1 + 0x27c) * (float)param_2[10]);
        param_2[0x1d] = (int)(*(float *)(param_1 + 0x280) * (float)param_2[0xb]);
        param_2[0x1e] = (int)(*(float *)(param_1 + 0x284) * (float)param_2[0xc]);
        param_2[0x1f] = (int)(*(float *)(param_1 + 0x288) * (float)param_2[0xd]);
        param_2[0x20] = (int)(*(float *)(param_1 + 0x28c) * (float)param_2[0xe]);
        param_2[0x21] = (int)(*(float *)(param_1 + 0x290) * (float)param_2[0xf]);
        param_2[0x22] = (int)(*(float *)(param_1 + 0x294) * (float)param_2[0x10]);
        param_2[0x23] = (int)(*(float *)(param_1 + 0x298) * (float)param_2[0x11]);
        param_2[0x24] = (int)(*(float *)(param_1 + 0x29c) * (float)param_2[0x12]);
        param_2[0x25] = (int)(*(float *)(param_1 + 0x2a0) * (float)param_2[0x13]);
        param_2[0x26] = (int)(*(float *)(param_1 + 0x2a4) * (float)param_2[0x14]);
        fVar1 = *(float *)(param_1 + 0x2a8);
        *(undefined1 *)((int)param_2 + 0x5d) = 1;
        param_2[0x27] = (int)(fVar1 * (float)param_2[0x15]);
      }
      param_2[0x28] = (int)(*(float *)(param_1 + 0x2ac) * (float)param_2[0x16]);
      if (((char)param_2[5] == '\0') || (*(char *)(param_1 + 0x268) == '\0')) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      *(undefined1 *)(param_2 + 0x17) = uVar5;
      *(uint *)param_2[4] = *(uint *)param_2[4] & ~*(uint *)(param_2[3] + 0xc);
      *(undefined1 *)(param_2 + 0x29) = 0;
    }
    return;
  }
  if ((**(byte **)(iVar2 + 0x44) & 1) == 0) {
    iVar7 = *(int *)(param_1 + 0x14);
    while ((iVar7 != 0 &&
           (iVar7 = *(int *)(param_1 + 0x14),
           (**(uint **)(iVar7 + 0x21c) & *(uint *)(*(int *)(iVar7 + 0x218) + 0xc)) != 0))) {
      param_1 = *(int *)(param_1 + 0x14);
      iVar7 = *(int *)(param_1 + 0x14);
    }
    iVar7 = *(int *)(param_1 + 0x218);
    puVar4 = *(uint **)(param_1 + 0x21c);
    if (*(int *)(iVar7 + 4) == 0) {
      *puVar4 = *puVar4 & ~*(uint *)(iVar7 + 0xc);
    }
    else {
      iVar8 = *(int *)(iVar7 + 8);
      if (iVar8 != 0) {
        iVar7 = *(int *)(iVar7 + 4) - (int)puVar4;
        do {
          *puVar4 = *puVar4 & ~*(uint *)(iVar7 + (int)puVar4);
          puVar4 = puVar4 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    acStack_1401[1] = 0;
  }
  else {
    FUN_0056d380(*(byte **)(iVar2 + 0x44),0,*(undefined4 *)(iVar2 + 0x4c));
    param_1 = *(int *)(iVar2 + 0x17c);
    acStack_1401[1] = 1;
  }
  aiStack_1004[1] = param_1;
  iVar7 = 1;
  do {
    iVar8 = aiStack_1004[iVar7];
    iVar3 = *(int *)(iVar8 + 0x14);
    if (iVar3 == 0) {
      if (*(char *)(iVar2 + 0x205) == '\0') {
        if (*(char *)(iVar8 + 0x221) != '\0') {
          *(undefined4 *)(iVar8 + 0x26c) = *(undefined4 *)(iVar8 + 0x224);
          *(undefined4 *)(iVar8 + 0x270) = *(undefined4 *)(iVar8 + 0x228);
          *(undefined4 *)(iVar8 + 0x274) = *(undefined4 *)(iVar8 + 0x22c);
          *(undefined4 *)(iVar8 + 0x278) = *(undefined4 *)(iVar8 + 0x230);
          *(undefined4 *)(iVar8 + 0x27c) = *(undefined4 *)(iVar8 + 0x234);
          *(undefined4 *)(iVar8 + 0x280) = *(undefined4 *)(iVar8 + 0x238);
          *(undefined4 *)(iVar8 + 0x284) = *(undefined4 *)(iVar8 + 0x23c);
          *(undefined4 *)(iVar8 + 0x288) = *(undefined4 *)(iVar8 + 0x240);
          *(undefined4 *)(iVar8 + 0x28c) = *(undefined4 *)(iVar8 + 0x244);
          *(undefined4 *)(iVar8 + 0x290) = *(undefined4 *)(iVar8 + 0x248);
          *(undefined4 *)(iVar8 + 0x294) = *(undefined4 *)(iVar8 + 0x24c);
          *(undefined4 *)(iVar8 + 0x298) = *(undefined4 *)(iVar8 + 0x250);
          *(undefined4 *)(iVar8 + 0x29c) = *(undefined4 *)(iVar8 + 0x254);
          *(undefined4 *)(iVar8 + 0x2a0) = *(undefined4 *)(iVar8 + 600);
          *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar8 + 0x25c);
          *(undefined4 *)(iVar8 + 0x2a8) = *(undefined4 *)(iVar8 + 0x260);
        }
        *(char *)(iVar8 + 0x269) = *(char *)(iVar8 + 0x221);
      }
      else if (*(char *)(iVar8 + 0x221) == '\0') {
        *(undefined4 *)(iVar8 + 0x26c) = *(undefined4 *)(iVar2 + 0x208);
        *(undefined4 *)(iVar8 + 0x270) = *(undefined4 *)(iVar2 + 0x20c);
        *(undefined4 *)(iVar8 + 0x274) = *(undefined4 *)(iVar2 + 0x210);
        *(undefined4 *)(iVar8 + 0x278) = *(undefined4 *)(iVar2 + 0x214);
        *(undefined4 *)(iVar8 + 0x27c) = *(undefined4 *)(iVar2 + 0x218);
        *(undefined4 *)(iVar8 + 0x280) = *(undefined4 *)(iVar2 + 0x21c);
        *(undefined4 *)(iVar8 + 0x284) = *(undefined4 *)(iVar2 + 0x220);
        *(undefined4 *)(iVar8 + 0x288) = *(undefined4 *)(iVar2 + 0x224);
        *(undefined4 *)(iVar8 + 0x28c) = *(undefined4 *)(iVar2 + 0x228);
        *(undefined4 *)(iVar8 + 0x290) = *(undefined4 *)(iVar2 + 0x22c);
        *(undefined4 *)(iVar8 + 0x294) = *(undefined4 *)(iVar2 + 0x230);
        *(undefined4 *)(iVar8 + 0x298) = *(undefined4 *)(iVar2 + 0x234);
        *(undefined4 *)(iVar8 + 0x29c) = *(undefined4 *)(iVar2 + 0x238);
        *(undefined4 *)(iVar8 + 0x2a0) = *(undefined4 *)(iVar2 + 0x23c);
        *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar2 + 0x240);
        *(undefined4 *)(iVar8 + 0x2a8) = *(undefined4 *)(iVar2 + 0x244);
        *(undefined1 *)(iVar8 + 0x269) = 1;
      }
      else {
        *(float *)(iVar8 + 0x26c) = *(float *)(iVar8 + 0x224) * *(float *)(iVar2 + 0x208);
        *(float *)(iVar8 + 0x270) = *(float *)(iVar8 + 0x228) * *(float *)(iVar2 + 0x20c);
        *(float *)(iVar8 + 0x274) = *(float *)(iVar8 + 0x22c) * *(float *)(iVar2 + 0x210);
        *(float *)(iVar8 + 0x278) = *(float *)(iVar8 + 0x230) * *(float *)(iVar2 + 0x214);
        *(float *)(iVar8 + 0x27c) = *(float *)(iVar8 + 0x234) * *(float *)(iVar2 + 0x218);
        *(float *)(iVar8 + 0x280) = *(float *)(iVar8 + 0x238) * *(float *)(iVar2 + 0x21c);
        *(float *)(iVar8 + 0x284) = *(float *)(iVar8 + 0x23c) * *(float *)(iVar2 + 0x220);
        *(float *)(iVar8 + 0x288) = *(float *)(iVar8 + 0x240) * *(float *)(iVar2 + 0x224);
        *(float *)(iVar8 + 0x28c) = *(float *)(iVar8 + 0x244) * *(float *)(iVar2 + 0x228);
        *(float *)(iVar8 + 0x290) = *(float *)(iVar8 + 0x248) * *(float *)(iVar2 + 0x22c);
        *(float *)(iVar8 + 0x294) = *(float *)(iVar8 + 0x24c) * *(float *)(iVar2 + 0x230);
        *(float *)(iVar8 + 0x298) = *(float *)(iVar8 + 0x250) * *(float *)(iVar2 + 0x234);
        *(float *)(iVar8 + 0x29c) = *(float *)(iVar8 + 0x254) * *(float *)(iVar2 + 0x238);
        *(float *)(iVar8 + 0x2a0) = *(float *)(iVar8 + 600) * *(float *)(iVar2 + 0x23c);
        *(float *)(iVar8 + 0x2a4) = *(float *)(iVar8 + 0x25c) * *(float *)(iVar2 + 0x240);
        fVar1 = *(float *)(iVar2 + 0x244);
        *(undefined1 *)(iVar8 + 0x269) = 1;
        *(float *)(iVar8 + 0x2a8) = *(float *)(iVar8 + 0x260) * fVar1;
      }
      *(float *)(iVar8 + 0x2ac) = *(float *)(iVar8 + 0x264) * *(float *)(iVar2 + 0x248);
      if ((*(char *)(iVar8 + 0x220) == '\0') || (*(char *)(iVar2 + 0x204) == '\0')) {
LAB_00583afe:
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      if (*(char *)(iVar3 + 0x269) == '\0') {
        if (*(char *)(iVar8 + 0x221) != '\0') {
          *(undefined4 *)(iVar8 + 0x26c) = *(undefined4 *)(iVar8 + 0x224);
          *(undefined4 *)(iVar8 + 0x270) = *(undefined4 *)(iVar8 + 0x228);
          *(undefined4 *)(iVar8 + 0x274) = *(undefined4 *)(iVar8 + 0x22c);
          *(undefined4 *)(iVar8 + 0x278) = *(undefined4 *)(iVar8 + 0x230);
          *(undefined4 *)(iVar8 + 0x27c) = *(undefined4 *)(iVar8 + 0x234);
          *(undefined4 *)(iVar8 + 0x280) = *(undefined4 *)(iVar8 + 0x238);
          *(undefined4 *)(iVar8 + 0x284) = *(undefined4 *)(iVar8 + 0x23c);
          *(undefined4 *)(iVar8 + 0x288) = *(undefined4 *)(iVar8 + 0x240);
          *(undefined4 *)(iVar8 + 0x28c) = *(undefined4 *)(iVar8 + 0x244);
          *(undefined4 *)(iVar8 + 0x290) = *(undefined4 *)(iVar8 + 0x248);
          *(undefined4 *)(iVar8 + 0x294) = *(undefined4 *)(iVar8 + 0x24c);
          *(undefined4 *)(iVar8 + 0x298) = *(undefined4 *)(iVar8 + 0x250);
          *(undefined4 *)(iVar8 + 0x29c) = *(undefined4 *)(iVar8 + 0x254);
          *(undefined4 *)(iVar8 + 0x2a0) = *(undefined4 *)(iVar8 + 600);
          *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar8 + 0x25c);
          *(undefined4 *)(iVar8 + 0x2a8) = *(undefined4 *)(iVar8 + 0x260);
        }
        *(char *)(iVar8 + 0x269) = *(char *)(iVar8 + 0x221);
      }
      else if (*(char *)(iVar8 + 0x221) == '\0') {
        *(undefined4 *)(iVar8 + 0x26c) = *(undefined4 *)(iVar3 + 0x26c);
        *(undefined4 *)(iVar8 + 0x270) = *(undefined4 *)(iVar3 + 0x270);
        *(undefined4 *)(iVar8 + 0x274) = *(undefined4 *)(iVar3 + 0x274);
        *(undefined4 *)(iVar8 + 0x278) = *(undefined4 *)(iVar3 + 0x278);
        *(undefined4 *)(iVar8 + 0x27c) = *(undefined4 *)(iVar3 + 0x27c);
        *(undefined4 *)(iVar8 + 0x280) = *(undefined4 *)(iVar3 + 0x280);
        *(undefined4 *)(iVar8 + 0x284) = *(undefined4 *)(iVar3 + 0x284);
        *(undefined4 *)(iVar8 + 0x288) = *(undefined4 *)(iVar3 + 0x288);
        *(undefined4 *)(iVar8 + 0x28c) = *(undefined4 *)(iVar3 + 0x28c);
        *(undefined4 *)(iVar8 + 0x290) = *(undefined4 *)(iVar3 + 0x290);
        *(undefined4 *)(iVar8 + 0x294) = *(undefined4 *)(iVar3 + 0x294);
        *(undefined4 *)(iVar8 + 0x298) = *(undefined4 *)(iVar3 + 0x298);
        *(undefined4 *)(iVar8 + 0x29c) = *(undefined4 *)(iVar3 + 0x29c);
        *(undefined4 *)(iVar8 + 0x2a0) = *(undefined4 *)(iVar3 + 0x2a0);
        *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar3 + 0x2a4);
        *(undefined4 *)(iVar8 + 0x2a8) = *(undefined4 *)(iVar3 + 0x2a8);
        *(undefined1 *)(iVar8 + 0x269) = 1;
      }
      else {
        *(float *)(iVar8 + 0x26c) = *(float *)(iVar3 + 0x26c) * *(float *)(iVar8 + 0x224);
        *(float *)(iVar8 + 0x270) = *(float *)(iVar3 + 0x270) * *(float *)(iVar8 + 0x228);
        *(float *)(iVar8 + 0x274) = *(float *)(iVar3 + 0x274) * *(float *)(iVar8 + 0x22c);
        *(float *)(iVar8 + 0x278) = *(float *)(iVar3 + 0x278) * *(float *)(iVar8 + 0x230);
        *(float *)(iVar8 + 0x27c) = *(float *)(iVar3 + 0x27c) * *(float *)(iVar8 + 0x234);
        *(float *)(iVar8 + 0x280) = *(float *)(iVar3 + 0x280) * *(float *)(iVar8 + 0x238);
        *(float *)(iVar8 + 0x284) = *(float *)(iVar3 + 0x284) * *(float *)(iVar8 + 0x23c);
        *(float *)(iVar8 + 0x288) = *(float *)(iVar3 + 0x288) * *(float *)(iVar8 + 0x240);
        *(float *)(iVar8 + 0x28c) = *(float *)(iVar3 + 0x28c) * *(float *)(iVar8 + 0x244);
        *(float *)(iVar8 + 0x290) = *(float *)(iVar3 + 0x290) * *(float *)(iVar8 + 0x248);
        *(float *)(iVar8 + 0x294) = *(float *)(iVar3 + 0x294) * *(float *)(iVar8 + 0x24c);
        *(float *)(iVar8 + 0x298) = *(float *)(iVar3 + 0x298) * *(float *)(iVar8 + 0x250);
        *(float *)(iVar8 + 0x29c) = *(float *)(iVar3 + 0x29c) * *(float *)(iVar8 + 0x254);
        *(float *)(iVar8 + 0x2a0) = *(float *)(iVar3 + 0x2a0) * *(float *)(iVar8 + 600);
        *(float *)(iVar8 + 0x2a4) = *(float *)(iVar3 + 0x2a4) * *(float *)(iVar8 + 0x25c);
        fVar1 = *(float *)(iVar3 + 0x2a8);
        *(undefined1 *)(iVar8 + 0x269) = 1;
        *(float *)(iVar8 + 0x2a8) = fVar1 * *(float *)(iVar8 + 0x260);
      }
      *(float *)(iVar8 + 0x2ac) = *(float *)(iVar3 + 0x2ac) * *(float *)(iVar8 + 0x264);
      if ((*(char *)(iVar8 + 0x220) == '\0') || (*(char *)(iVar3 + 0x268) == '\0'))
      goto LAB_00583afe;
      uVar5 = 1;
    }
    *(undefined1 *)(iVar8 + 0x268) = uVar5;
    *(undefined1 *)(iVar8 + 0x2b0) = 0;
    iVar3 = *(int *)(*(int *)(iVar8 + 0x10) + 0x170);
    if (iVar3 != 0) {
      iVar9 = 0;
      if (0 < iVar3) {
        pfVar6 = (float *)(*(int *)(iVar8 + 0x208) + 100);
        do {
          if (*(char *)(iVar8 + 0x269) == '\0') {
            if (*(char *)((int)pfVar6 + -0x4f) != '\0') {
              pfVar6[-1] = pfVar6[-0x13];
              *pfVar6 = pfVar6[-0x12];
              pfVar6[1] = pfVar6[-0x11];
              pfVar6[2] = pfVar6[-0x10];
              pfVar6[3] = pfVar6[-0xf];
              pfVar6[4] = pfVar6[-0xe];
              pfVar6[5] = pfVar6[-0xd];
              pfVar6[6] = pfVar6[-0xc];
              pfVar6[7] = pfVar6[-0xb];
              pfVar6[8] = pfVar6[-10];
              pfVar6[9] = pfVar6[-9];
              pfVar6[10] = pfVar6[-8];
              pfVar6[0xb] = pfVar6[-7];
              pfVar6[0xc] = pfVar6[-6];
              pfVar6[0xd] = pfVar6[-5];
              pfVar6[0xe] = pfVar6[-4];
            }
            *(char *)((int)pfVar6 + -7) = *(char *)((int)pfVar6 + -0x4f);
          }
          else if (*(char *)((int)pfVar6 + -0x4f) == '\0') {
            pfVar6[-1] = *(float *)(iVar8 + 0x26c);
            *pfVar6 = *(float *)(iVar8 + 0x270);
            pfVar6[1] = *(float *)(iVar8 + 0x274);
            pfVar6[2] = *(float *)(iVar8 + 0x278);
            pfVar6[3] = *(float *)(iVar8 + 0x27c);
            pfVar6[4] = *(float *)(iVar8 + 0x280);
            pfVar6[5] = *(float *)(iVar8 + 0x284);
            pfVar6[6] = *(float *)(iVar8 + 0x288);
            pfVar6[7] = *(float *)(iVar8 + 0x28c);
            pfVar6[8] = *(float *)(iVar8 + 0x290);
            pfVar6[9] = *(float *)(iVar8 + 0x294);
            pfVar6[10] = *(float *)(iVar8 + 0x298);
            pfVar6[0xb] = *(float *)(iVar8 + 0x29c);
            pfVar6[0xc] = *(float *)(iVar8 + 0x2a0);
            pfVar6[0xd] = *(float *)(iVar8 + 0x2a4);
            pfVar6[0xe] = *(float *)(iVar8 + 0x2a8);
            *(undefined1 *)((int)pfVar6 + -7) = 1;
          }
          else {
            pfVar6[-1] = pfVar6[-0x13] * *(float *)(iVar8 + 0x26c);
            *pfVar6 = pfVar6[-0x12] * *(float *)(iVar8 + 0x270);
            pfVar6[1] = pfVar6[-0x11] * *(float *)(iVar8 + 0x274);
            pfVar6[2] = pfVar6[-0x10] * *(float *)(iVar8 + 0x278);
            pfVar6[3] = pfVar6[-0xf] * *(float *)(iVar8 + 0x27c);
            pfVar6[4] = pfVar6[-0xe] * *(float *)(iVar8 + 0x280);
            pfVar6[5] = pfVar6[-0xd] * *(float *)(iVar8 + 0x284);
            pfVar6[6] = pfVar6[-0xc] * *(float *)(iVar8 + 0x288);
            pfVar6[7] = pfVar6[-0xb] * *(float *)(iVar8 + 0x28c);
            pfVar6[8] = pfVar6[-10] * *(float *)(iVar8 + 0x290);
            pfVar6[9] = pfVar6[-9] * *(float *)(iVar8 + 0x294);
            pfVar6[10] = pfVar6[-8] * *(float *)(iVar8 + 0x298);
            pfVar6[0xb] = pfVar6[-7] * *(float *)(iVar8 + 0x29c);
            pfVar6[0xc] = pfVar6[-6] * *(float *)(iVar8 + 0x2a0);
            pfVar6[0xd] = pfVar6[-5] * *(float *)(iVar8 + 0x2a4);
            fVar1 = *(float *)(iVar8 + 0x2a8);
            *(undefined1 *)((int)pfVar6 + -7) = 1;
            pfVar6[0xe] = pfVar6[-4] * fVar1;
          }
          pfVar6[0xf] = pfVar6[-3] * *(float *)(iVar8 + 0x2ac);
          if ((*(char *)(pfVar6 + -0x14) == '\0') || (*(char *)(iVar8 + 0x268) == '\0')) {
            uVar5 = 0;
          }
          else {
            uVar5 = 1;
          }
          *(undefined1 *)(pfVar6 + -2) = uVar5;
          *(undefined1 *)(pfVar6 + 0x10) = 0;
          iVar9 = iVar9 + 1;
          pfVar6 = pfVar6 + 0x2e;
        } while (iVar9 < *(int *)(*(int *)(iVar8 + 0x10) + 0x170));
      }
    }
    iVar3 = iVar7 + -1;
    if ((acStack_1401[iVar7] != '\0') && (*(int *)(iVar8 + 0x20) != 0)) {
      aiStack_1004[iVar7] = *(int *)(iVar8 + 0x20);
      acStack_1401[iVar7] = '\x01';
      iVar3 = iVar7;
    }
    iVar7 = iVar3;
    if (*(int *)(iVar8 + 0x18) != 0) {
      aiStack_1004[iVar7 + 1] = *(int *)(iVar8 + 0x18);
      acStack_1401[iVar7 + 1] = '\x01';
      iVar7 = iVar7 + 1;
    }
    if (iVar7 == 0) {
      return;
    }
  } while( true );
}

