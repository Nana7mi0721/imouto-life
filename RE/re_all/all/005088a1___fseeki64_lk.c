
/* Library Function - Single Match
    __fseeki64_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __fseeki64_lk(FILE *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined8 uVar3;
  longlong lVar4;
  
  if (((param_1->_flag & 0x83U) == 0) || (((param_4 != 0 && (param_4 != 1)) && (param_4 != 2)))) {
    puVar2 = (undefined4 *)FUN_00501f2f();
    *puVar2 = 0x16;
  }
  else {
    param_1->_flag = param_1->_flag & 0xffffffef;
    if (param_4 == 1) {
      uVar3 = __ftelli64_lk(param_1);
      param_3 = param_3 + (int)((ulonglong)uVar3 >> 0x20) + (uint)CARRY4(param_2,(uint)uVar3);
      param_4 = 0;
    }
    __flush(param_1);
    uVar1 = param_1->_flag;
    if ((char)uVar1 < '\0') {
      param_1->_flag = uVar1 & 0xfffffffc;
    }
    else if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
      param_1->_bufsiz = 0x200;
    }
    lVar4 = __lseeki64(param_1->_file,CONCAT44(param_4,param_3),unaff_EDI);
    if (lVar4 != -1) {
      return 0;
    }
  }
  return 0xffffffff;
}

